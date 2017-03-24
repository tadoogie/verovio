/////////////////////////////////////////////////////////////////////////////
// Name:        elementpart.h
// Author:      Laurent Pugin
// Created:     2017
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_ELEMENT_PART_H__
#define __VRV_ELEMENT_PART_H__

#include "atts_cmn.h"
#include "atts_shared.h"
#include "layerelement.h"

namespace vrv {

//----------------------------------------------------------------------------
// Flag
//----------------------------------------------------------------------------

/**
 * This class models a stem as a layer element part and has not direct MEI equivlatent.
 */
class Flag : public LayerElement {
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method resets all attribute classes
     */
    ///@{
    Flag();
    virtual ~Flag();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Flag"; }
    virtual ClassId GetClassId() const { return FLAG; }
    ///@}

    /** Override the method since alignment is required */
    virtual bool HasToBeAligned() const { return true; }
    
    wchar_t GetSmuflCode(data_STEMDIRECTION stemDir);
    
    Point GetStemUpSE(Doc *doc, int staffSize, bool graceSize, wchar_t &code);
    Point GetStemDownNW(Doc *doc, int staffSize, bool graceSize, wchar_t &code);

    //----------//
    // Functors //
    //----------//

    /**
     * Overwritten version of Save that avoids anything to be written
     */
    ///@{
    virtual int Save(FunctorParams *) { return FUNCTOR_CONTINUE; }
    virtual int SaveEnd(FunctorParams *) { return FUNCTOR_CONTINUE; }
    ///@}

    /**
     * See Object::ResetDrawing
     */
    virtual int ResetDrawing(FunctorParams *functorParams);

private:
    //
public:
    /** The number of flags to be drawn */
    int m_drawingNbFlags;

private:
};

//----------------------------------------------------------------------------
// NoteHead
//----------------------------------------------------------------------------

/**
 * This class models a stem as a layer element part and has not direct MEI equivlatent.
 */
class NoteHead : public LayerElement {
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method resets all attribute classes
     */
    ///@{
    NoteHead();
    virtual ~NoteHead();
    virtual void Reset();
    virtual std::string GetClassName() const { return "NoteHead"; }
    virtual ClassId GetClassId() const { return NOTEHEAD; }
    ///@}

    //----------//
    // Functors //
    //----------//

    /**
     * Overwritten version of Save that avoids anything to be written
     */
    ///@{
    virtual int Save(FunctorParams *) { return FUNCTOR_CONTINUE; }
    virtual int SaveEnd(FunctorParams *) { return FUNCTOR_CONTINUE; }
    ///@}

private:
    //
public:
    //
private:
};

//----------------------------------------------------------------------------
// Stem
//----------------------------------------------------------------------------

/**
 * This class models a stem as a layer element part and has not direct MEI equivlatent.
 */
class Stem : public LayerElement, public AttStems, public AttStemsCmn {
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method resets all attribute classes
     */
    ///@{
    Stem();
    virtual ~Stem();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Stem"; }
    virtual ClassId GetClassId() const { return STEM; }
    ///@}

    /** Override the method since alignment is required */
    virtual bool HasToBeAligned() const { return true; }

    /**
     * Add an element (only flag supported) to a stem.
     */
    virtual void AddChild(Object *object);

    /**
     * @name Setter and getter for darwing stem direction and length
     */
    ///@{
    data_STEMDIRECTION GetDrawingStemDir() { return m_drawingStemDir; }
    void SetDrawingStemDir(data_STEMDIRECTION drawingStemDir) { m_drawingStemDir = drawingStemDir; }
    int GetDrawingStemLen() { return m_drawingStemLen; }
    void SetDrawingStemLen(int drawingStemLen) { m_drawingStemLen = drawingStemLen; }
    ///@}

    //----------//
    // Functors //
    //----------//
    
    /**
     * See Object::CalcStem
     */
    virtual int CalcStem(FunctorParams *functorParams);

    /**
     * Overwritten version of Save that avoids anything to be written
     */
    ///@{
    virtual int Save(FunctorParams *) { return FUNCTOR_CONTINUE; }
    virtual int SaveEnd(FunctorParams *) { return FUNCTOR_CONTINUE; }
    ///@}

    /**
     * See Object::ResetDrawing
     */
    virtual int ResetDrawing(FunctorParams *functorParams);

private:
    //
public:
    //
private:
    /**
     *
     */
    data_STEMDIRECTION m_drawingStemDir;
    /**
     *
     */
    int m_drawingStemLen;
};

} // namespace vrv

#endif
