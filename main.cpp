///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "QtCore/QCoreApplication"
#include "QtCore/QDebug"
#include "Syllogism/Equivalence.hpp"
#include "Syllogism/Comparison.hpp"
#include "Syllogism/Context.hpp"
#include "Syllogism/Meme.hpp"

///////////////////////////////////////////////////////////////////////////////
/// Main /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/**
 * @paragraph This function tests the syllogistic relationships
 * @brief main()
 * @param int intArguments
 * @param char* chrArguments[]
 * @return int
 */
int main(int intArguments, char* chrArguments[])
{
	// Instantiate our context
	Syllogism::Context* sylContext = new Syllogism::Context();
	// Instantiate our memes
	Syllogism::Meme* memeMan       = sylContext->createMeme("Man");
	Syllogism::Meme* memeMammal    = sylContext->createMeme("Mammal");
	Syllogism::Meme* memeAnimal    = sylContext->createMeme("Animal");
	Syllogism::Meme* memeInanimate = sylContext->createMeme("Inanimate");
	// Add the syllogisms to the context
	sylContext->addSyllogism(memeMan, Syllogism::Equivalence::Equality, memeMammal);
	sylContext->addSyllogism(memeMan, Syllogism::Equivalence::Equality, memeAnimal);
	// Sould print true
	qDebug() << "Man Is Mammal:     " << sylContext->interrogate(memeMan, Syllogism::Equivalence::Equality, memeMammal).toString();
	// Should print true
	qDebug() << "Man Is Animal:     " << sylContext->interrogate(memeMan, Syllogism::Equivalence::Equality, memeAnimal).toString();
	// Should print false
	qDebug() << "Man Is Inanimate:  " << sylContext->interrogate(memeMan, Syllogism::Equivalence::Equality, memeInanimate).toString();
	// We're done
	return 0;
///////////////////////////////////////////////////////////////////////////////
} // End Main ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
