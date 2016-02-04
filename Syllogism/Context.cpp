///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "Context.hpp"

///////////////////////////////////////////////////////////////////////////////
/// Syllogism Namespace //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace Syllogism
{
	///////////////////////////////////////////////////////////////////////////
	/// Public Methods ///////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void Context::addSyllogism(Syllogism::Meme *memeKey, Syllogism::Equivalence eqvEquivalence, Syllogism::Meme *memeValue)
	{
		// Create the pair
		QPair<Equivalence, Meme*> qpRelation;
		// Populate the pair
		qpRelation.first  = eqvEquivalence;
		qpRelation.second = memeValue;
		// Create the relations
		QList<QPair<Equivalence, Meme*>> qlRelations;
		// Check for the key
		if (this->mAssociations.contains(memeKey)) {
			// Localize the relations
			qlRelations = this->mAssociations.value(memeKey);
		}
		// Add the relation
		qlRelations.append(qpRelation);
		// Reset the association
		this->mAssociations.insert(memeKey, qlRelations);
	}

	Comparison Context::interrogate(Meme* memeKey, Equivalence eqvEquivalence, Meme* memeValue)
	{
		// Create the comparison structure
		Comparison instComparison(Equivalence::Unknown, false);
		// Check for associations
		if (this->mAssociations.isEmpty() || !this->mAssociations.contains(memeKey)) {
			// Reset the structure
			instComparison.equivalence = Equivalence::Unknown;
			instComparison.matched     = false;
		} else if (this->mAssociations.value(memeKey).contains(QPair<Equivalence, Meme*>(eqvEquivalence, memeValue))) {
			// Reset the structure
			instComparison.equivalence = eqvEquivalence;
			instComparison.matched     = true;
		} else {
			// Localize the pair
			QList<QPair<Equivalence, Meme*>> qlRelations = this->mAssociations.value(memeKey);
			// Iterate over the pairs
			for (int intPair = 0; intPair < qlRelations.size(); ++intPair) {
				// Create our recursive comparison
				Comparison instRecursiveComparison = this->interrogate(qlRelations.value(intPair).second, qlRelations.value(intPair).first, memeValue);
				// Interrogate the pair
				if (instRecursiveComparison.getMatched()) {
					// We're done
					return instRecursiveComparison;
				}
			}
		}
		// We're done
		return instComparison;
	}

///////////////////////////////////////////////////////////////////////////////
} // End Syllogism Namespace /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
