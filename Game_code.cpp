#include <SFML/Graphics.hpp> 
#include <string> 
using namespace sf; 
int main() { 
    RenderWindow window(VideoMode({800, 600}), "TENNIS GAME"); 
    window.setFramerateLimit(60); 
 
    // Bat 
    RectangleShape paddle1({10.f, 100.f}); 
    paddle1.setPosition({50.f, 250.f}); 
    paddle1.setFillColor(Color::White); 
 
    RectangleShape paddle2({10.f, 100.f}); 
    paddle2.setPosition({740.f, 250.f}); 
    paddle2.setFillColor(Color::White); 
 
    CircleShape ball(10.f); 
    ball.setPosition({395.f, 295.f}); 
    ball.setFillColor(Color::White); 
 
    // velocity 
    Vector2f ballVelocity{-4.f, -3.f}; 
    float paddleSpeed = 5.f; 
 
    // Score 
    int score1 = 0; 
    int score2 = 0; 
 
    Font font; 
    if (!font.openFromFile("resources/arial.ttf")) { 
        return -1;  
    } 
 
Text scoreText(font, "0 - 0", 30);        
scoreText.setFillColor(Color::White); 
scoreText.setPosition({340.f, 10.f});          
 
    while (window.isOpen()) { 
        while (auto e = window.pollEvent()) { 
            if (e->is<Event::Closed>()) 
                window.close(); 
        } 
if(score1<10 && score2<10){ 
        // Player 1 
        if (Keyboard::isKeyPressed(Keyboard::Scan::W) && paddle1.getPosition().y 
> 0) 
            paddle1.move({0.f, -paddleSpeed}); 
        if (Keyboard::isKeyPressed(Keyboard::Scan::S) && paddle1.getPosition().y 
< 500) 
            paddle1.move({0.f, paddleSpeed}); 
 
        // Player 2 
        if (Keyboard::isKeyPressed(Keyboard::Scan::Up) && 
paddle2.getPosition().y > 0) 
            paddle2.move({0.f, -paddleSpeed}); 
        if (Keyboard::isKeyPressed(Keyboard::Scan::Down) && 
paddle2.getPosition().y < 500) 
            paddle2.move({0.f, paddleSpeed}); 
 
        ball.move(ballVelocity); 
 
        if (ball.getPosition().y + ball.getRadius() <= 0 ||          ball.getPosition().y + 
ball.getRadius()*2 >= 600) 
            ballVelocity.y *= -1.f; 
 
        FloatRect ballBounds = ball.getGlobalBounds(); 
        FloatRect paddle1Bounds = paddle1.getGlobalBounds(); 
        FloatRect paddle2Bounds = paddle2.getGlobalBounds(); 
        if (ballBounds.findIntersection(paddle1Bounds) || 
ballBounds.findIntersection(paddle2Bounds)) { 
            ballVelocity.x *= -1.f; 
        } 
 
        if (ball.getPosition().x < 0) {  
            score2++; 
            ball.setPosition({395.f, 295.f}); 
            ballVelocity = {-4.f, -3.f}; 
        } 
        if (ball.getPosition().x > 800) { 
            score1++; 
            ball.setPosition({395.f, 295.f}); 
            ballVelocity = {4.f, 3.f}; 
        } 
 
     
        scoreText.setString(std::to_string(score1) + " : " + std::to_string(score2)); 
         
        window.clear(Color::Black); 
        window.draw(paddle1); 
        window.draw(paddle2); 
        window.draw(ball); 
window.draw(scoreText); 
window.display(); 
} 
else{    
Text ext(font, "PLAYER WIN", 50);        
ext.setFillColor(Color::White); 
ext.setPosition({240.f, 270.f}); 
int sco=score1>score2?1:2; 
ext.setString("PLAYER " + std::to_string(sco)+" WIN"); 
window.clear(Color::Black); 
window.draw(ext); 
window.display(); 
} 
} 
return 0;   }
