#include <iostream>
#include <vector>
class Naipe{

    public:
        char letra;
        std::vector<std::string> cartas;
        int contagemDeRepetida;

        Naipe(char _letra)
        {
            contagemDeRepetida = 0;
            letra = _letra;
        }

        void AddCard(std::string card){
            for (std::string c : cartas)
            {
                if (card == c){
                    contagemDeRepetida++;
                    return;
                }
            }
            cartas.push_back(card);
        }

        std::string GetResult()
        {
            if (contagemDeRepetida > 0) return "erro";
            int faltando = 13 - ((int)cartas.size());
            std::string result = std::to_string(faltando);
            return result;
        }
};

int main(){
    Naipe copas = Naipe('C');  
    Naipe espadas = Naipe('E');  
    Naipe ouros = Naipe('U');  
    Naipe paus = Naipe('P');  

    std::string enter;
    std::cin >> enter;

    char naipe;
    std::string card;

    for (int i = 0; i < enter.size(); i+= 3)
    {
        card = enter[i];
        card += enter[i+1];
        naipe = enter[i+2];
        
        switch (naipe)
        {
        case 'C':
            copas.AddCard(card);
            break;
        case 'E':
            espadas.AddCard(card);
            break;
        case 'U':
            ouros.AddCard(card);
            break;
        case 'P':
            paus.AddCard(card);
            break;
        }
    }
    std::cout << copas.GetResult() << std::endl;
    std::cout << espadas.GetResult() << std::endl;
    std::cout << ouros.GetResult() << std::endl;
    std::cout << paus.GetResult() << std::endl;
    return 0;
}