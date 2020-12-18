#include "doctest.h"
#include "piece.h"

using namespace chest;

void LesInfosSontExactes(const Piece& p,const bool b, const std::string img)
{
    FAST_REQUIRE_EQ(p.couleur(), b);
    FAST_REQUIRE_EQ(p.image(), img);
}



TEST_CASE("[piece] la piece est bien construite")
{

    bool testb = 0;
    std::string img = "lienIMG";

    LesInfosSontExactes(Piece{testb,img},testb,img);
}
