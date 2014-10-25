#version 330

layout (std140) uniform Matrices {
	mat4 pvm;
} ;

in vec4 position;
in vec3 in_color;
in vec4 texCoord;

out vec4 color;

void main()
{
	color = texCoord;
	gl_Position = pvm * position ;
} 
