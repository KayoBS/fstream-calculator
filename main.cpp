#include<iostream>
#include<string>
//#include<fstream>

int sum( int, int );
int sub( int, int );
int mlt( int, int );
double dvs( int, int );

int main( int argc, char *argv[] ) {

  std::string operand(argv[2]);

  if( argc == 4 ) {
    if( operand == "+" ) {
      std::cout << sum( std::stoi(argv[1]), std::stoi(argv[3]) ) << '\n';
    }
    else if( operand == "-" ){
      std::cout << sub( std::stoi(argv[1]), std::stoi(argv[3]) ) << '\n';
    }
    else if( operand == "." ){
      std::cout << mlt( std::stoi(argv[1]), std::stoi(argv[3]) ) << '\n';
    }
    else if( operand == "/" ){
      std::cout << dvs( std::stoi(argv[1]), std::stoi(argv[3]) ) << '\n';
    }
    else {
      std::cout << "invalid operand argument" << '\n';
    }
    
  }
  else {
    std::cout << "invalid number of arguments" << '\n';
  }

  return 0;
}

int sum( int a, int b ) {
  return ( a + b );
}
int sub( int a, int b ) {
  return ( a - b );
}
int mlt( int a, int b ) {
  return ( a * b );
}
double dvs( int a, int b ) {
  return ( a / b );
}
