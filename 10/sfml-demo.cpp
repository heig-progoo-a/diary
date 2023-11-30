// Demo SFML that displays a circle that moves around the screen
#include <SFML/Graphics.hpp>
#include <vector> 
#include <random> 

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f position;

    public:
    Ball(float x, float y, float radius) : x{x}, y{y}, radius{radius} {
        shape.setRadius(radius);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color(100, 250, 50, 80));
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color::Cyan);
        velocity = sf::Vector2f(0.2, 0.2);
    }
   
    void update(sf::RenderWindow &window, std::vector<Ball> &balls) {
        // Velocity
        // Bounce on the edges
        if (x + radius * 2 > window.getSize().x || x < 0) velocity.x = -velocity.x;
        if (y + radius * 2 > window.getSize().y || y < 0) velocity.y = -velocity.y;

        // Move the circle
        x += velocity.x;
        y += velocity.y;

        // Bounce on collision
        for (auto &ball: balls) {
            if (ball.x == x && ball.y == y) continue;
            // Bounce on eadge of circle collision
            if (x + radius * 2 > ball.x && x < ball.x + ball.radius * 2 && y + radius * 2 > ball.y && y < ball.y + ball.radius * 2) {
                velocity.x = -velocity.x;
                velocity.y = -velocity.y;
            }
        }
        shape.setPosition(x, y);
    }

    void display(sf::RenderWindow &window) {
        window.draw(shape);
    }

    float x, y, radius;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(120);
    
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();

    // Create 100 balls
    std::vector<Ball> balls;
    for (int i = 0; i < 100; i++) {
        // Place randomly on the screen
        balls.push_back(Ball(
            rand() % window.getSize().x,
            rand() % window.getSize().y,
            10
        ));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
                // Increase radius
                for (auto &ball: balls) {
                    ball.radius += 1;
                    ball.shape.setRadius(ball.radius);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // Increase velocity
                for (auto &ball: balls) {
                    ball.velocity.x += 0.1;
                    ball.velocity.y += 0.1;
                }
            }
        }
        window.clear();
        // Update the balls
        for (auto &ball: balls) { 
            ball.update(window, balls);
            ball.display(window);
        }

        window.display();
    }
    return 0;
}