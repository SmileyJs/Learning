#version 330 core

out vec4 color;
in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float alpha;

void main() {
	// color = vec4(ourColor, 0.0f);
	color = mix(texture(texture1, ourTexCoord), texture(texture2, (1-ourTexCoord)), alpha);
}