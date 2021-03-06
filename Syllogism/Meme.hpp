///////////////////////////////////////////////////////////////////////////////
/// Definitions //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#ifndef SYLLOGISM_MEME_H
#define SYLLOGISM_MEME_H

///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "QtCore/QObject"
#include "QtCore/QString"

///////////////////////////////////////////////////////////////////////////////
/// Syllogism Namespace //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace Syllogism
{
	///////////////////////////////////////////////////////////////////////////
	/// Syllogism::Meme Class Definition /////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	class Meme : public QObject
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
			 * @paragraph This property contains the textual representation of the meme
			 * @brief Syllogism::Meme::mTextualRepresentation
			 * @var QString
			 */
			QString mTextualRepresentation;

			///////////////////////////////////////////////////////////////////
			/// Public Methods & Properties //////////////////////////////////
			/////////////////////////////////////////////////////////////////

			public:

				///////////////////////////////////////////////////////////////
				/// Constructors /////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This constructor instantiates an empty Meme
				 * @brief Syllogism::Meme::Meme()
				 * @param QObject* objParent [0]
				 */
				inline explicit Meme(QObject* objParent = 0) : QObject(objParent) {}

				/**
				 * @paragraph This constructor instantiates the Meme with a textual representation
				 * @brief Syllogism::Meme::Meme()
				 * @param QString strText
				 * @param QObject* objParent [0]
				 */
				inline explicit Meme(QString strText, QObject* objParent = 0) : QObject(objParent), mTextualRepresentation(strText) {}

				///////////////////////////////////////////////////////////////
				/// Converters ///////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method converts the Meme into a string representation
				 * @brief Syllogism::Meme::toString()
				 * @return QString
				 */
				inline QString toString() {
					// Return the string representation of the Meme
					return QString("m[%1]").arg(this->mTextualRepresentation);
				}

				///////////////////////////////////////////////////////////////
				/// Getters //////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method returns the Meme's textual representation from the instance
				 * @brief Syllogism::Meme::getText()
				 * @return QString Syllogism::Meme::mTextualRepresentation
				 */
				inline QString getText() { return this->mTextualRepresentation; }

				///////////////////////////////////////////////////////////////
				/// Setters //////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method sets the textual representation of the Meme into the instance
				 * @brief Syllogism::Meme::setText()
				 * @param QString strText
				 * @return void
				 */
				inline void setText(QString strText) { this->mTextualRepresentation = strText; }

	///////////////////////////////////////////////////////////////////////////
	}; // End Syllogism::Meme Class Definition ///////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // End Syllogism Namespace /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#endif // End Definitions ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
