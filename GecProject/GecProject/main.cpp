/*
    GecProject - For GEC students to use as a start point for their projects.
    Already has SFML linked and ImGui set up.
*/

#include "ExternalHeaders.h"
#include "RedirectCout.h"
#include "Graphics.h"
#include <filesystem> //REMOVE THIS

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

    // Clock required by ImGui
    sf::Clock uiDeltaClock;
  
    //Graphics setup
    Graphics* MainGraphics = new Graphics;

    //UNKNOWN WHERE DEFAULT FILE PATH POINTS TO.
    //Until then, hard coded the file path.

    //Found default path and all looks good, but sf::Texture LoadTexture doesn't seem to use the default path?
    //std::filesystem::current_path() returns the expected path.

    sf::Texture Tex;
    if (!MainGraphics->LoadTexture("//Data//Textures//MaleZombie//idle_combined.png", "ZombieIdle"))
        return 1;
    if (!MainGraphics->LoadTexture("/Data/Textures/MaleZombie/walk_combined.png", "ZombieWalk"))
        return 2;

    MainGraphics->CreateChar2D("Zombie");
    MainGraphics->AddAnimationSet("Idle", "Zombie", AnimationSetData{ "ZombieIdle", 15, false, true });
    MainGraphics->AddAnimationSet("Walk", "Zombie", AnimationSetData{ "ZombieWalk", 10, false, true });

    MainGraphics->Render("Zombie", sf::Vector2f(200, 200), sf::Vector2f(1, 1), "Idle", 2);

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

        MainGraphics->Draw(window);

        // UI needs drawing last
        ImGui::SFML::Render(window);

        window.display();

        sf::sleep(Time);
    }

	ImGui::SFML::Shutdown();

    delete MainGraphics;

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

    // ImGui::Checkbox("AnimState", &AnimState);
    //ImGui::SliderFloat("X Position", &XPosition, 0.0f, 800.0f - 100);
    
   // ImGui::Checkbox("Wireframe", &m_wireframe);	// A checkbox linked to a member variable

   // ImGui::Checkbox("Cull Face", &m_cullFace);

   // ImGui::SliderFloat("Speed", &gAnimationSpeed, 0.01f, 0.3f);	// Slider from 0.0 to 1.0

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::End();
}