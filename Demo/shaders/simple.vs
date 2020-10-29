#version 120

in vec4 position;

uniform mat4 m_perspective;
uniform mat4 m_view;
uniform mat4 m_model;

void main() {

    gl_Position = m_perspective * m_view * m_model * position;
}
