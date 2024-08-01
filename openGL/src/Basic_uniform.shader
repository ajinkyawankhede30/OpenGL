#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textCoord;

out vec2 v_Textcoord;

void main()
{
	gl_Position = position;
	v_Textcoord = textCoord;
};

#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec2 v_Textcoord;

uniform vec4 u_color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_Textcoord);
	//color = vec4(1.0, 0.75, 0.5, 1.0);
	//color = u_color;
	color = texColor;
};