/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "KreogCom.hpp"
#include <iostream>

using namespace std;

int main ()
{
 KreogCom k(42, 42, 101010);
  cout << boolalpha << "Has partner after creation: " << (k.getCom() != 0) << endl;
  k.addCom(50, 30, 35);
  cout << boolalpha << "Has partner after AddPartner(): " << (k.getCom() != 0) << endl;
  k.removeCom();
  cout << boolalpha << "Has partner after KillPartner(): " << (k.getCom() != 0) << endl;
  k.removeCom();
  k.addCom(56, 25, 65);
  k.addCom(73, 34, 51);
  k.addCom(20, 8, 109);
  std::cout << "==========" << std::endl;
  k.locateSquad();
  std::cout << "==========" << std::endl;
  std :: cout << "PING : ";
  k.ping();
  std::cout << "==========" << std::endl;
  std :: cout << "PING : ";
  k.getCom()->ping();
  std::cout << "==========" << std::endl;
  k.getCom()->removeCom();
  k.locateSquad();
  std::cout << "==========" << std::endl;
  k.addCom(20, 8, 10);
  delete k.getCom();
  k.removeCom();
  k.removeCom();
  std::cout << "==========" << std::endl;
  k.locateSquad();
  std::cout << "==========" << std::endl;
  KreogCom const * kc = &k;
  kc->locateSquad();
}