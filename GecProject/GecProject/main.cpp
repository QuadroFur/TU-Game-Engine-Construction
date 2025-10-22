/*
    GecProject - For GEC students to use as a start point for their projects.
    Already has SFML linked and ImGui set up.
*/

#include "ExternalHeaders.h"
#include "RedirectCout.h"

#include "Object.h"
#include "Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>

float XPosition;
float YPosition;

float RValue;
float GValue;
float BValue;

bool AnimState;

void DefineGUI();

int main()
{
    // Redirect cout to the Visual Studio output pane
    outbuf ob;
    std::streambuf* sb{ std::cout.rdbuf(&ob) };

    // Redirect cerr
    outbuferr oberr;
    std::streambuf* sberr{ std::cerr.rdbuf(&oberr) };

    // Turn on memory leak checking
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "GEC Start Project");

    // Set up ImGui (the UI library)
    if (!ImGui::SFML::Init(window))
        return -1;

    // Create a simple shape to draw
    

    //New Zombie Handling

    Player NewPlayer;
    if (!NewPlayer.IdleTexture.loadFromFile("Data/Textures/MaleZombie/idle_combined.png"))
    {
        return -1;
    }
    if (!NewPlayer.WalkingTexture.loadFromFile("Data/Textures/MaleZombie/walk_combined.png"))
    {
        return -1;
    }
    NewPlayer.Size = sf::Vector2f(432 / 20, 521 / 20);
    NewPlayer.Construct2D(14);
    NewPlayer.UpdateCharState();

    //Old Zombie Handling

    // Clock required by ImGui
    sf::Clock uiDeltaClock;
  
    sf::Time Time = sf::milliseconds(50);
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Feed ImGui
            ImGui::SFML::ProcessEvent(window, event.value());

            // User clicked on window close X
            if (event->is<sf::Event::Closed>())
                window.close();                          
        }

        // ImGui must be updated each frame
        ImGui::SFML::Update(window, uiDeltaClock.restart());

        // The UI gets defined each time
        DefineGUI();

        // Clear the window
        window.clear();

        NewPlayer.KeyInput();
        NewPlayer.GameTick();
        NewPlayer.Draw(window);
        //Replace the above with a loop for all stored Objects, to render each.

        // UI needs drawing last
        ImGui::SFML::Render(window);

        window.display();

        sf::sleep(Time);
    }

    std::cout << "Finished!" << std::endl;

	ImGui::SFML::Shutdown();

    return 0;
}

/*
    Use IMGUI for a simple on screen GUI
    See: https://github.com/ocornut/imgui/wiki/
*/
void DefineGUI()
{
    // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::Begin("SpriteControler");				// Create a window

    ImGui::Checkbox("AnimState", &AnimState);

    ImGui::Text("Sprite Position: ");
    ImGui::SliderFloat("X Position", &XPosition, 0.0f, 800.0f - 100);
    ImGui::SliderFloat("Y Position", &YPosition, 0.0f, 600.0f - 100);

    ImGui::Text("Sprite Colour: ");

    ImGui::SliderFloat("R", &RValue, 0.0f, 255.0f);
    ImGui::SliderFloat("G", &GValue, 0.0f, 255.0f);
    ImGui::SliderFloat("B", &BValue, 0.0f, 255.0f);
    
   // ImGui::Checkbox("Wireframe", &m_wireframe);	// A checkbox linked to a member variable

   // ImGui::Checkbox("Cull Face", &m_cullFace);

   // ImGui::SliderFloat("Speed", &gAnimationSpeed, 0.01f, 0.3f);	// Slider from 0.0 to 1.0

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::End();
}