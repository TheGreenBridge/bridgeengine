#pragma once

layout(location = 0)in vec3 position;

uniform mat4 pr_matrix;
uniform mat4 view_matrix;


void main(){
	
	gl_Position = pr_matrix * view_matrix * vec4(position,1.0);

}