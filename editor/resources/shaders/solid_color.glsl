#shader vertex
#version 330 core
layout (location = 0) in vec3 a_Position;

layout (std140, binding = 0) uniform Matrices
{
    mat4 u_Projection;
    mat4 u_View;
};
uniform mat4 u_Model;


void main()
{
    gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);
}

#shader fragment
#version 330 core
out vec4 FragColor;

uniform vec4 u_Color;

void main()
{ 
    FragColor = u_Color;
}