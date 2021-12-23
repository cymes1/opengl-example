#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

out vec4 v_Color;

uniform mat4 u_MVP;
uniform vec4 u_Color;

void main()
{
    gl_Position = u_MVP * position;
    v_Color = u_Color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_Color;

void main()
{
    color = v_Color;
}
