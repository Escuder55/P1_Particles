#include <imgui\imgui.h>
#include <imgui\imgui_impl_sdl_gl3.h>
#include <iostream>



////////SON LAS FUNCIONES QUE UTILIZAREMOS PARA ACTUALIZAR POSICIONES DE LAS PARTICULAS
namespace LilSpheres
{
	extern const int maxParticles;	
	extern void updateParticles(int startIdx, int count, float* array_data);
}
////////////////variables que 
float myParticles[12]; 
float *myArray;

int initIndex;
int numParticles;

bool show_test_window = false;
void GUI() {
	bool show = true;
	ImGui::Begin("Physics Parameters", &show, 0);

	// Do your GUI code here....
	{	
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);//FrameRate
		
	}
	// .........................
	
	ImGui::End();

	// Example code -- ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

void PhysicsInit() {
	// Do your initialization code here...
	
	myParticles [12] =  { (2.0f, 2.0f, 2.0f, 4.0f, 4.0f, 4.0f, -2.0f, -2.0f, 2.0f, -4.0f, -4.0f, 4.0f) };

	myArray = myParticles;
		
	initIndex = 0;
	numParticles = 4;





	// ...................................
}

void PhysicsUpdate(float dt) {
	// Do your update code here...

	LilSpheres::updateParticles(initIndex, numParticles, myArray);
	// ...........................
}

void PhysicsCleanup() {
	// Do your cleanup code here...
	// ............................
}