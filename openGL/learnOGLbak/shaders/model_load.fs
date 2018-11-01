#version 330 core

in vec2 texCoord;
in vec3 fragPos;
in vec3 normal;

out vec4 fragColor;

struct Material
{
	sampler2D texture_diffUse0;
	sampler2D texture_specular0;
	sampler2D texture_normal0;
	sampler2D texture_height0;
	sampler2D emission;
	float shininess;
};

struct DirLight
{
	vec3 direction;

	vec3 ambient;
	vec3 diffUse;
	vec3 specular;
};

struct PointLight
{
	vec3 position;

	vec3 ambient;
	vec3 diffUse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

struct SpotLight
{
	vec3 direction;
	vec3 position;

	vec3 ambient;
	vec3 diffUse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;

	float cutOff;
	float outerCutOff;
};

uniform sampler2D texture_diffUse1;
uniform DirLight dirLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

uniform vec3 viewPos;
uniform Material material;

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calcSpotLight(SpotLight light, vec3 norm, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 norm = normalize(normal);
	vec3 viewDir = normalize(viewPos - fragPos);

	vec3 result = calcDirLight(dirLight, norm, viewDir);
	result += calcPointLight(pointLight, norm, fragPos, viewDir);
	result += calcSpotLight(spotLight, norm, fragPos, viewDir);

	fragColor = vec4(result, 1.0f);
}

vec3 calcDirLight(DirLight light, vec3 norm, vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 diffUse = light.diffUse * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular0, texCoord));

	return ambient + diffUse + specular;
}

vec3 calcPointLight(PointLight light, vec3 norm, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 diffUse = light.diffUse * diff * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular0, texCoord));

	// // attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1 / (light.constant + light.linear*distance + light.quadratic*distance*distance);

	ambient *= attenuation;
	diffUse *= attenuation;
	specular *= attenuation;

	return ambient + diffUse + specular;
}

vec3 calcSpotLight(SpotLight light, vec3 norm, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 diffUse = light.diffUse * diff * vec3(texture(material.texture_diffUse0, texCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular0, texCoord));

	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;	
	float intensity = clamp((theta - light.outerCutOff)/epsilon, 0.0f, 1.0f);
	diffUse *= intensity;
	specular *= intensity;

	float distance = length(light.position - fragPos);
	float attenuation = 1 / (light.constant + light.linear*distance + light.quadratic*distance*distance);

	ambient *= attenuation;
	diffUse *= attenuation;
	specular *= attenuation;

	return ambient + diffUse + specular;
}
