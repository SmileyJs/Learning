#version 330 core

out vec4 fragColor;

in vec3 fragPos;
in vec3 normal;
in vec2 texCoords;

struct Material
{
	sampler2D diffUse;
	sampler2D specular;
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

uniform DirLight dirLight;
#define POINT_LIGHT_NUM	4
uniform PointLight pointLight[POINT_LIGHT_NUM];
uniform SpotLight spotLight;

uniform vec3 viewPos;
uniform Material material;

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 norm = normalize(normal);
	vec3 viewDir = normalize(viewPos - fragPos);

	vec3 result = calcDirLight(dirLight, norm, viewDir);
	for (int i = 0; i != POINT_LIGHT_NUM; ++i)
		result += calcPointLight(pointLight[i], norm, fragPos, viewDir);

	result += calcSpotLight(spotLight, norm, fragPos, viewDir);

	// vec3 emission = vec3(texture(material.emission, texCoords));

	fragColor = vec4(result, 1.0f);
}

vec3 calcDirLight(DirLight light, vec3 norm, vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.diffUse, texCoords));
	vec3 diffUse = light.diffUse * diff * vec3(texture(material.diffUse, texCoords));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));

	return ambient + diffUse + specular;
}

vec3 calcPointLight(PointLight light, vec3 norm, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.diffUse, texCoords));
	vec3 diffUse = light.diffUse * diff * vec3(texture(material.diffUse, texCoords));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));

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

	vec3 ambient = light.ambient * vec3(texture(material.diffUse, texCoords));
	vec3 diffUse = light.diffUse * diff * vec3(texture(material.diffUse, texCoords));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));

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