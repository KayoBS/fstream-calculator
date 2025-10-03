#include "lib/lib.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  if (argc == 3) {
    // CRIAÇÃO DE VARIÁVEIS
    std::string inputName(argv[1]);
    std::string outputName(argv[2]);
    // variáveis dos operadores
    int operand1, operand2;
    double result;

    std::ifstream inFile(inputName);   // arquivo de leitura
    std::ofstream outFile(outputName); // arquivo de escrita

    // variável para guardar a expressão
    std::string expression;

    // LEITURA DO ARQUIVO DE ENTRADA
    // leitura do arquivo com as expressões aritméticas
    if (inFile.is_open()) {

      std::cout << "reading operands and operator from " << inputName << '\n';
      std::getline(inFile, expression);

      inFile.close();
    }

    else {
      std::cout << "input file \"" << inputName << "\" does not exists!";
    }

    // evita erros de runtime
    if (!expression.empty()) {
      // PROCESSO DE 'TOKENIZAÇÃO
      std::vector<std::string> token = tokenize(&expression);
      std::string operation = token[1];
      operand1 = std::stoi(token[0]);
      operand2 = std::stoi(token[2]);

      // std::cout << operation << '\n'; // ADD || SUB || MLT || DVS
      // std::cout << operand1 << '\n';  // 1
      // std::cout << operand2 << '\n';  // 1

      if (operation != "+" && operation != "-" && operation != "." &&
          operation != "/") {
        std::cout << "invalid operator argument!\n";
      }
      // cálculo
      else {

        if (operation == "+") {
          result = sum(operand1, operand2);
        }

        else if (operation == "-") {
          result = sub(operand1, operand2);
        }

        else if (operation == ".") {
          result = mlt(operand1, operand2);
        }

        else if (operation == "/") {
          result = dvs(operand1, operand2);
        }
      }

      // ESCRITA DO ARQUIVO DE SAÍDA
      if (outFile.is_open()) {
        std::cout << "writting result to " << outputName << " file\n";
        outFile << result;
        outFile.close();
      }

      else {
        std::cout << "output file \"" << outputName << "\" does not exists";
      }
    }

    else {
      std::cout << inputName << " file is empty! please read a non-empty file";
    }
  }

  else {
    std::cout << "invalid number of arguments!\n";
    std::cout << "expected 2, received " << (argc - 1) << '\n';
  }

  return 0;
}
