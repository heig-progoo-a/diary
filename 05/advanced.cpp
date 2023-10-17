
struct Point {
    int x, y;
};

struct GuiInterface {
    virtual void onLeftClick(std::function<Point()> action) = 0;
    virtual void onRightClick(std::function<Point()> action) = 0;
    virtual void display() = 0;

    virtual MouseEvent execute_and_display(&table) = 0;
};

class Game {
    GuiInterface &interface
    Game(GuiInterface &interface) : interface{interface} {
        interface.onLeftClick([](){ this->onLeftClick() }) // Listener
        interface.display();
    }

    void run() {
        while(notFinished) {
            display();
            while(!eventTriggered);
            eventTriggered = false;
        }
    }
    private:
    void onLeftClick(Point p) {
        eventTrigerred = true;
    }
}

class ConsoleInterface : public GuiInterface {
    std::function<Point()> leftAction, rightAction
    void onLeftClick(std::function<Point()> action) override {
        leftAction = action;
    }
    void onRightClick(std::function<Point()> action) override {
        rightAction = action;
    }
    void display() override {
        std::cout << "Board...."; 
        std::string command;
        int x, y;
        std::cin >> command >> x >> y
        if (command == "left click") {
            leftAction(x, y);
        } 
        if (command == "right click") {
            rightAction(x, y);
        }
    }
};

int main() {
    ConsoleInterface gui(std::cin, std::cout)
    Game game{gui}
}