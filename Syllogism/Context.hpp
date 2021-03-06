///////////////////////////////////////////////////////////////////////////////
/// Definitions //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#ifndef SYLLOGISM_CONTEXT_H
#define SYLLOGISM_CONTEXT_H

///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "QtCore/QDebug"
#include "QtCore/QList"
#include "QtCore/QMap"
#include "QtCore/QObject"
#include "QtCore/QPair"
#include "Equivalence.hpp"
#include "Comparison.hpp"
#include "Meme.hpp"

///////////////////////////////////////////////////////////////////////////////
/// Syllogism Namespace //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace Syllogism
{
	///////////////////////////////////////////////////////////////////////////
	/// Syllogism::Context Class Definition //////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	class Context : public QObject
	{
		///////////////////////////////////////////////////////////////////////
		/// QObject Classification ///////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		Q_OBJECT

		///////////////////////////////////////////////////////////////////////
		/// Protected Methods & Properties ///////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		protected:

			///////////////////////////////////////////////////////////////////
			/// Properties ///////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This property contains our syllogism context container
			 * @brief Syllogism::Context::mAssociations
			 * @var QMap<Meme*, QList<QPair<Syllogism::Equivalence, Syllogism::Meme*>>>
			 */
			QMap<Meme*, QList<QPair<Equivalence, Meme*>>> mAssociations;

		///////////////////////////////////////////////////////////////////////
		/// Public Methods & Properties //////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		public:

			///////////////////////////////////////////////////////////////////
			/// Constructor //////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method instantiates an empty Context
			 * @brief Syllogism::Context::Context()
			 * @param QObject* objParent [0]
			 */
			inline explicit Context(QObject* objParent = 0) : QObject(objParent) {}

			///////////////////////////////////////////////////////////////////
			/// Methods //////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method defines a syllogism for a given equivalence type
			 * @brief Syllogism::Context::addSyllogism()
			 * @param Syllogism::Meme* memeKey
			 * @param Syllogism::Equivalence eqvEquivalence
			 * @param Syllogism::Meme* memeValue
			 * @return void
			 */
			void addSyllogism(Meme* memeKey, Equivalence eqvEquivalence, Meme* memeValue);

			/**
			 * @paragraph This method determines if a given syllogism for an equivalence type is valid
			 * @brief Syllogism::Context::interrogate()
			 * @param Syllogism::Meme* memeKey
			 * @param Syllogism::Equivalence eqvEquivalence
			 * @param Syllogism::Meme* memeValue
			 * @return Syllogism::Comparison
			 */
			Comparison interrogate(Meme* memeKey, Equivalence eqvEquivalence, Meme* memeValue);

			///////////////////////////////////////////////////////////////////
			/// Helpers //////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method is a wrapper for instantiating a new meme
			 * @brief Syllogism::Context::createMeme()
			 * @param QString strText
			 * @return Syllogism::Meme*
			 */
			inline Meme* createMeme(QString strText) { return new Meme(strText); }

	///////////////////////////////////////////////////////////////////////////
	}; // End Syllogism::Context Class Definition ////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // End Syllogism Namespace /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#endif // End Definitions ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
