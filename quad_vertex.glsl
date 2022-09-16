#version 460 core

layout (location = 0) in vec4 positon;

uniform mat4 projection;
uniform mat4 modelView;

out gl_PerVertex {
    vec4 gl_Position;
};

void main() {
    gl_Position = projection * modelView * positon;
}