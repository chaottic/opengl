#version 460 core

layout (location = 0) in vec4 positon;

out gl_PerVertex {
    vec4 gl_Position;
};

void main() {
    gl_Position = positon;
}
