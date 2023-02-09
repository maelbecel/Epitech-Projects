/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex06/Buzz.hpp"
#include "../ex06/Woody.hpp"
#include "../ex06/Picture.hpp"
#include "../ex06/Toy.hpp"
#include "../ex06/ToyStory.hpp"

Test(Buzz, buzz)
{
    Buzz buzz("Bobzz", "../ex06/Toy.hpp");
    cr_assert_eq(buzz.speak("hello"), true);
    cr_assert_eq(buzz.speak_es("hello"), true);
}

Test(Woody, woody)
{
    Woody woody("Bobzz", "../ex06/Toy.hpp");
    cr_assert_eq(woody.speak("hello"), true);
}

Test(Picture, picture)
{
    Picture p;
    Picture p2(p);
    Picture p3("../ex06/Toyss.hpp");
    p2 = p3;
    cr_assert_eq(p3.data, "ERROR");
    cr_assert_eq(p3.getPictureFromFile("./ex06/Toy.hpp"), true);
}

Test(Toy, toy)
{
    Toy t1;
    Toy t2 = t1;
    Toy toy (Toy::BASIC_TOY, "ham", "./ex06/Toy.hpp");
    cr_assert_eq(toy.speak("hello"), true);
    cr_assert_eq(toy.speak_es("hello"), false);
    cr_assert_eq(toy.getType(), Toy::BASIC_TOY);
    cr_assert_eq(toy.getName(), "ham");
    toy.setName("jej");
    cr_assert_eq(toy.getName(), "jej");
    cr_assert_eq(toy.setAscii("./ex06/Toy.hpp"), true);
    cr_assert_eq(t1.setAscii("./ex06/Tocy.hpp"), false);
    t1 = toy;
    cr_assert_eq(t1.getAscii(), toy.getAscii());
    t1 << "jej";
    cr_assert_eq(t1.getAscii(), "jej");
    t1.getLastError();
    std::cout << t1 << std::endl;
}

Test(Error, error)
{
    Toy::Error e1(Toy::Error::SPEAK);
    std::cout << "e1.what() == " << e1.what() << std::endl;
    std::cout << "e1.where() == " << e1.where() << std::endl;

    Toy::Error e2(Toy::Error::PICTURE);
    std::cout << "e2.what() == " << e2.what() << std::endl;
    std::cout << "e2.where() == " << e2.where() << std::endl;

    Toy::Error e3(Toy::Error::UNKNOWN);
    std::cout << "e3.what() == " << e3.what() << std::endl;
    std::cout << "e3.where() == " << e3.where() << std::endl;
}

Test(ToyStory, toy_story)
{
    Buzz b ("buzzi") ;
    Woody w ("wood") ;
    ToyStory t;
    ToyStory::tellMeAStory("s.txt", b, &Toy::speak_es , w , &Toy::speak);
    ToyStory::tellMeAStory("./tests/superStory.txt", b, &Toy::speak_es , w , &Toy::speak);
    ToyStory::tellMeAStory("./tests/superStory2.txt", b, &Toy::speak_es , w , &Toy::speak);
    ToyStory::tellMeAStory("./tests/superStory.txt", b, &Toy::speak_es , w , &Toy::speak_es);
}