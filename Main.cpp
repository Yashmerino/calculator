#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>

int pass = 0; //Vars
float resultOutPut = 0;
int point = 0;
float temp;
char operation = ' ';
std::string num1 = "";
std::string num2 = "";
sf::Text num1SF, num2SF, operationSF, resultSF;

bool CheckPressedButton(sf::Sprite& sprite, sf::RenderWindow& window) { //Getting mouse position converted into world coords
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); 
        sf::FloatRect bounds = sprite.getGlobalBounds();

        if (bounds.contains(mousePos))
            return true;
        else
            return false;
}

void ColorButton(sf::Sprite& sprite, sf::RenderWindow& window) {
    if (CheckPressedButton(sprite, window)) {
        sprite.setColor(sf::Color::Green);
    }
    else
        sprite.setColor(sf::Color::White);
}

void ClickNumber(sf::Sprite& sprite, sf::RenderWindow& window, std::string str){
    if (CheckPressedButton(sprite, window)) {
        resultOutPut = 0;
        resultSF.setString("");
        if (pass == 0)
            num1 = num1 + str;
        else if (pass == 1)
            num2 = num2 + str;
        std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
    }
}

void ClickOperator(sf::Sprite& sprite, sf::RenderWindow& window, char op) {
    if (CheckPressedButton(sprite, window)) {
        point = 0;
        resultOutPut = 0;
        resultSF.setString("");
        pass = 1;
        operation = op;
        std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
    }
}

void PressNumber(sf::Sprite& sprite, sf::RenderWindow& window, char op) {
    resultOutPut = 0;
    resultSF.setString("");
    if (pass == 0)
        num1 = num1 + op;
    else
        num2 = num2 + op;
    std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
}

void PressOperator(sf::Sprite& sprite, sf::RenderWindow& window, char op) {
    point = 0;
    resultOutPut = 0;
    resultSF.setString("");
    pass = 1;
    operation = op;
    std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
}

void DefaultColor(sf::Sprite& sprite) {
    sprite.setColor(sf::Color::White);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(240, 300), "Calculator", sf::Style::Titlebar | sf::Style::Close); //Creating a window
    sf::RectangleShape screenCalc; //Creating a shape
    sf::RectangleShape backgroundButtons;
    backgroundButtons.setFillColor(sf::Color::Black);
    backgroundButtons.setSize(sf::Vector2f(240, 240));
    backgroundButtons.setPosition(sf::Vector2f(0, 60));
    screenCalc.setFillColor(sf::Color(204, 231, 232));
    screenCalc.setOutlineThickness(10);
    screenCalc.setOutlineColor(sf::Color(25, 94, 131));
    screenCalc.setSize(sf::Vector2f(240, 50));
  
    sf::Texture number0T; number0T.loadFromFile("Sprites/zero.png"); //Creatting textures and loading files
    sf::Texture number1T; number1T.loadFromFile("Sprites/one.png");
    sf::Texture number2T; number2T.loadFromFile("Sprites/two.png");
    sf::Texture number3T; number3T.loadFromFile("Sprites/three.png");
    sf::Texture number4T; number4T.loadFromFile("Sprites/four.png");
    sf::Texture number5T; number5T.loadFromFile("Sprites/five.png");
    sf::Texture number6T; number6T.loadFromFile("Sprites/six.png");
    sf::Texture number7T; number7T.loadFromFile("Sprites/seven.png");
    sf::Texture number8T; number8T.loadFromFile("Sprites/eight.png");
    sf::Texture number9T; number9T.loadFromFile("Sprites/nine.png");
    sf::Texture plusT; plusT.loadFromFile("Sprites/plus.png");
    sf::Texture minusT; minusT.loadFromFile("Sprites/minus.png");
    sf::Texture divideT; divideT.loadFromFile("Sprites/divide.png");
    sf::Texture multiplicationT; multiplicationT.loadFromFile("Sprites/multiplication.png");
    sf::Texture pointT; pointT.loadFromFile("Sprites/point.png");
    sf::Texture resultT; resultT.loadFromFile("Sprites/result.png");
    number0T.setSmooth(true); number4T.setSmooth(true); number8T.setSmooth(true); resultT.setSmooth(true);
    number1T.setSmooth(true); number5T.setSmooth(true); number9T.setSmooth(true); divideT.setSmooth(true);
    number2T.setSmooth(true); number6T.setSmooth(true); plusT.setSmooth(true); multiplicationT.setSmooth(true);
    number3T.setSmooth(true); number7T.setSmooth(true); minusT.setSmooth(true); pointT.setSmooth(true);

    sf::Sprite number0S; number0S.setTexture(number0T); //Creatting sprites and setting texturess
    sf::Sprite number1S; number1S.setTexture(number1T);
    sf::Sprite number2S; number2S.setTexture(number2T);
    sf::Sprite number3S; number3S.setTexture(number3T);
    sf::Sprite number4S; number4S.setTexture(number4T);
    sf::Sprite number5S; number5S.setTexture(number5T);
    sf::Sprite number6S; number6S.setTexture(number6T);
    sf::Sprite number7S; number7S.setTexture(number7T);
    sf::Sprite number8S; number8S.setTexture(number8T);
    sf::Sprite number9S; number9S.setTexture(number9T);
    sf::Sprite plusS; plusS.setTexture(plusT);
    sf::Sprite minusS; minusS.setTexture(minusT);
    sf::Sprite multiplicationS; multiplicationS.setTexture(multiplicationT);
    sf::Sprite divideS; divideS.setTexture(divideT);
    sf::Sprite resultS; resultS.setTexture(resultT);
    sf::Sprite pointS; pointS.setTexture(pointT);

    number0S.setPosition(sf::Vector2f(60.0f, 240.0f)); //Setting the positions for sprites
    number1S.setPosition(sf::Vector2f(0.0f, 60.0f)); 
    number2S.setPosition(sf::Vector2f(60.0f, 60.0f));
    number3S.setPosition(sf::Vector2f(120.0f, 60.0f));
    number4S.setPosition(sf::Vector2f(0.0f, 120.0f));
    number5S.setPosition(sf::Vector2f(60.0f, 120.0f));
    number6S.setPosition(sf::Vector2f(120.0f, 120.0f));
    number7S.setPosition(sf::Vector2f(0.0f, 180.0f));
    number8S.setPosition(sf::Vector2f(60.0f, 180.0f));
    number9S.setPosition(sf::Vector2f(120.0f, 180.0f));
    resultS.setPosition(sf::Vector2f(120.0f, 240.0f));
    plusS.setPosition(sf::Vector2f(180.0f, 60.0f));
    minusS.setPosition(sf::Vector2f(180.0f, 120.0f));
    divideS.setPosition(sf::Vector2f(180.0f, 240.0f));
    multiplicationS.setPosition(sf::Vector2f(180.0f, 180.0f));
    pointS.setPosition(sf::Vector2f(0.0f, 240.0f));

    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");
    resultSF.setFillColor(sf::Color::Black);
    resultSF.setCharacterSize(24);
    resultSF.setString("");
    resultSF.setFont(font);
    resultSF.setPosition(0.f, 0.f);
    num1SF.setFont(font);
    num1SF.setFillColor(sf::Color::Black);
    num1SF.setCharacterSize(24);
    num2SF.setFont(font);
    num2SF.setFillColor(sf::Color::Black);
    num2SF.setCharacterSize(24);
    num2SF.setPosition(0.f, 20.f);
    operationSF.setFont(font);
    operationSF.setFillColor(sf::Color::Black);
    operationSF.setCharacterSize(24);
    operationSF.setFont(font);

    while (window.isOpen()) { //To prevent window instant close
        sf::Event evnt;
        while (window.pollEvent(evnt)) { //To make close button active
            switch (evnt.type) {
            case sf::Event::MouseLeft:
                DefaultColor(number0S);
                DefaultColor(number1S);
                DefaultColor(number2S);
                DefaultColor(number3S);
                DefaultColor(number4S);
                DefaultColor(number5S);
                DefaultColor(number6S);
                DefaultColor(number7S);
                DefaultColor(number8S);
                DefaultColor(number9S);
                DefaultColor(plusS);
                DefaultColor(minusS);
                DefaultColor(divideS);
                DefaultColor(multiplicationS);
                DefaultColor(resultS);
                DefaultColor(pointS);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                ColorButton(number0S, window);
                ColorButton(number1S, window);
                ColorButton(number2S, window);
                ColorButton(number3S, window);
                ColorButton(number4S, window);
                ColorButton(number5S, window);
                ColorButton(number6S, window);
                ColorButton(number7S, window);
                ColorButton(number8S, window);
                ColorButton(number9S, window);
                ColorButton(plusS, window);
                ColorButton(minusS, window);
                ColorButton(divideS, window);
                ColorButton(multiplicationS, window);
                ColorButton(resultS, window);
                ColorButton(pointS, window);
                break;
            case sf::Event::MouseButtonPressed: //Setting valeus for num1 and num2. Selecting the operation
                if (evnt.mouseButton.button == sf::Mouse::Left) {
                    if (CheckPressedButton(number0S, window)) {
                        resultOutPut = 0;
                        resultSF.setString("");
                        if (pass == 0 && num1 != "")
                            num1 = num1 + "0";
                        else if (pass == 1 && num2 != "")
                            num2 = num2 + "0";
                        std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
                    }

                    ClickNumber(number1S, window, "1");
                    ClickNumber(number2S, window, "2");
                    ClickNumber(number3S, window, "3");
                    ClickNumber(number4S, window, "4");
                    ClickNumber(number5S, window, "5");
                    ClickNumber(number6S, window, "6");
                    ClickNumber(number7S, window, "7");
                    ClickNumber(number8S, window, "8");
                    ClickNumber(number9S, window, "9");

                    ClickOperator(plusS, window, '+');
                    ClickOperator(minusS, window, '-');
                    ClickOperator(divideS, window, '/');
                    ClickOperator(multiplicationS, window, '*');
                    
                    if (CheckPressedButton(pointS, window)) {
                        resultOutPut = 0;
                        resultSF.setString("");
                        if (point == 0) {
                            if (pass == 0) {
                                point = 1;
                                num1 = num1 + ".";
                            }
                            else
                                num2 = num2 + ".";
                            std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
                        }
                    }
                    if (CheckPressedButton(resultS, window)) {
                        point = 0;
                        if (num1 == " " && num2 == "") {
                            num1 = "0";
                            num2 = "0";
                        }
                        if (num1 == " " || num2 == "") {
                            if (num1 == "")
                                num1 = "0";
                            if (num2 == "")
                                num2 = "0";
                        }

                        try {
                            switch (operation) {
                            case '+':
                                resultOutPut = std::stof(num1) + std::stof(num2);
                                break;
                            case '-':
                                resultOutPut = std::stof(num1) - std::stof(num2);
                                break;
                            case '/':
                                resultOutPut = std::stof(num1) / std::stof(num2);
                                break;
                            case '*':
                                resultOutPut = std::stof(num1) * std::stof(num2);
                                break;
                            }
                        }
                        catch (std::out_of_range& error) {
                            resultSF.setString("ERROR");
                        }

                        std::cout << "The result: " << num1 << " " << operation << " " << num2 << " = " << resultOutPut << std::endl;
                        if (modf(resultOutPut, &temp) == 0) {
                            if (resultSF.getString() != "ERROR") {
                                resultSF.setString(std::to_string((int)resultOutPut));
                            }
                        }
                        else {
                            if (resultSF.getString() != "ERROR") {
                                resultSF.setString(std::to_string(resultOutPut));
                            }
                        }
                        pass = 0;
                        num1 = "";
                        num2 = "";
                        operation = ' ';
                    }
                }
            case sf::Event::KeyPressed:
                if (evnt.key.code == sf::Keyboard::Num0 || evnt.key.code == sf::Keyboard::Numpad0) {
                    resultOutPut = 0;
                    resultSF.setString("");
                    if (pass == 0 && num1 != "")
                        num1 = num1 + "0";
                    else if (pass == 1 && num2 != "")
                        num2 = num2 + "0";
                    std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
                }
                if (evnt.key.code == sf::Keyboard::Num1 || evnt.key.code == sf::Keyboard::Numpad1) {
                    PressNumber(number1S, window, '1');
                }
                if (evnt.key.code == sf::Keyboard::Num2 || evnt.key.code == sf::Keyboard::Numpad2) {
                    PressNumber(number2S, window, '2');
                }
                if (evnt.key.code == sf::Keyboard::Num3 || evnt.key.code == sf::Keyboard::Numpad3) {
                    PressNumber(number3S, window, '3');
                }
                if (evnt.key.code == sf::Keyboard::Num4 || evnt.key.code == sf::Keyboard::Numpad4) {
                    PressNumber(number4S, window, '4');
                }
                if (evnt.key.code == sf::Keyboard::Num5 || evnt.key.code == sf::Keyboard::Numpad5) {
                    PressNumber(number5S, window, '5');
                }
                if (evnt.key.code == sf::Keyboard::Num6 || evnt.key.code == sf::Keyboard::Numpad6) {
                    PressNumber(number6S, window, '6');
                }
                if (evnt.key.code == sf::Keyboard::Num7 || evnt.key.code == sf::Keyboard::Numpad7) {
                    PressNumber(number7S, window, '7');
                }
                if (evnt.key.code == sf::Keyboard::Num8 || evnt.key.code == sf::Keyboard::Numpad8) {
                    PressNumber(number8S, window, '8');
                }
                if (evnt.key.code == sf::Keyboard::Num9 || evnt.key.code == sf::Keyboard::Numpad9) {
                    PressNumber(number9S, window, '9');
                }
                if (evnt.key.code == sf::Keyboard::Add) {
                    PressOperator(plusS, window, '+');
                }
                if (evnt.key.code == sf::Keyboard::Subtract) {
                    PressOperator(minusS, window, '-');
                }
                if (evnt.key.code == sf::Keyboard::Divide) {
                    PressOperator(divideS, window, '/');
                }
                if (evnt.key.code == sf::Keyboard::Multiply) {
                    PressOperator(multiplicationS, window, '*');
                }
                if (evnt.key.code == sf::Keyboard::Period) {
                    resultOutPut = 0;
                    resultSF.setString("");
                    if (point == 0) {
                        if (pass == 0) {
                            point = 1;
                            num1 = num1 + ".";
                        }
                        else
                            num2 = num2 + ".";
                        std::cout << "First number: " << num1 << "\nSecond number: " << num2 << "\nArithmetic operation: " << operation << std::endl << std::endl;
                    }
                }
                if (evnt.key.code == sf::Keyboard::Equal || evnt.key.code == sf::Keyboard::Enter) {
                    point = 0;
                    if (num1 == "" && num2 == "") {
                        num1 = "0";
                        num2 = "0";
                    }
                    if (num1 == "" || num2 == "") {
                        if (num1 == "")
                            num1 = "0";
                        if (num2 == "")
                            num2 = "0";
                    }

                    try {
                        switch (operation) {
                        case '+':
                            resultOutPut = std::stof(num1) + std::stof(num2);
                            break;
                        case '-':
                            resultOutPut = std::stof(num1) - std::stof(num2);
                            break;
                        case '/':
                            resultOutPut = std::stof(num1) / std::stof(num2);
                            break;
                        case '*':
                            resultOutPut = std::stof(num1) * std::stof(num2);
                            break;
                        }
                    }
                    catch(std::out_of_range& error){
                        resultSF.setString("ERROR");
                    }

                    if (modf(resultOutPut, &temp) == 0) {
                        if (resultSF.getString() != "ERROR") {
                            resultSF.setString(std::to_string((int)resultOutPut));
                        }
                    }
                    else {
                        if (resultSF.getString() != "ERROR") {
                            resultSF.setString(std::to_string(resultOutPut));
                        }
                    }

                    std::cout << "The result: " << num1 << " " << operation << " " << num2 << " = " << resultOutPut << std::endl;
                    pass = 0;
                    num1 = "";
                    num2 = "";
                    operation = ' ';
                }
            }
        }
            
            num1SF.setString(num1);
            num2SF.setString(num2);
            operationSF.setString(operation);
            operationSF.setPosition(num1SF.getLocalBounds().width + 10.f, 0.f);

            window.clear(sf::Color::White); //Drawing the sprites
            window.draw(screenCalc);
            window.draw(backgroundButtons);
            window.draw(number0S); 
            window.draw(number1S);
            window.draw(number2S);
            window.draw(number3S);
            window.draw(number4S);
            window.draw(number5S);
            window.draw(number6S);
            window.draw(number7S);
            window.draw(number8S);
            window.draw(number9S);
            window.draw(plusS);
            window.draw(minusS);
            window.draw(divideS);
            window.draw(multiplicationS);
            window.draw(pointS);
            window.draw(resultS);
            window.draw(num1SF);
            window.draw(operationSF);
            window.draw(num2SF);
            window.draw(resultSF);
            window.display();
        }

    std::cin.get();
    return 0;
}