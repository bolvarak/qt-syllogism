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

	bool Context::interrogate(Syllogism::Meme *memeKey, Syllogism::Equivalence eqvEquivalence, Syllogism::Meme *memeValue)
	{
		// Check for associations
		if (this->mAssociations.isEmpty() || !this->mAssociations.contains(memeKey)) {
			// We're done
			return false;
		}
		// Localize the pair
		QList<QPair<Equivalence, Meme*>> qlRelations = this->mAssociations.value(memeKey);
		// Check the list
		if (qlRelations.contains(QPair<Equivalence, Meme*>(eqvEquivalence, memeValue))) {
			// We're done
			return true;
		}
		// Iterate over the pairs
		for (int intPair = 0; intPair < qlRelations.size(); ++intPair) {
			// Interrogate the pair
			if (this->interrogate(qlRelations.value(intPair).second, qlRelations.value(intPair).first, memeValue)) {
				// We're done
				return true;
			}
		}
		// We're done
		return false;
	}

///////////////////////////////////////////////////////////////////////////////
} // End Syllogism Namespace /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
