#ifndef A01DetectorConstruction_h
#define A01DetectorConstruction_h 1

//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
// --------------------------------------------------------------
//

//------------------------------------------------
// The Virtual Monte Carlo examples
// Copyright (C) 2007 - 2014 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: root-vmc@cern.ch
//-------------------------------------------------

/// \file A01DetectorConstruction.hh
/// \brief Definition of the A01DetectorConstruction class 
///
/// Geant4 example A01 adapted to Virtual Monte Carlo

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4FieldManager.hh"

class B5MagneticField;

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4GenericMessenger;
class G4FieldManager;
class G4VisAttributes;

/// \ingroup A01
/// \brief The detector construction (defined via Geant4)

class A01DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    A01DetectorConstruction(G4bool useLocalMagField);
    virtual ~A01DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
    void SetArmAngle(G4double val);
    inline G4double GetArmAngle() { return fArmAngle; }

    void ConstructMaterials();

  private:
    void DefineCommands();

    G4GenericMessenger* fMessenger;

    static G4ThreadLocal B5MagneticField* fMagneticField;
    static G4ThreadLocal G4FieldManager* fFieldMgr;

    G4LogicalVolume* fMagneticLogical;

    std::vector<G4VisAttributes*> fVisAttributes;

    G4double fArmAngle;
    G4RotationMatrix* fArmRotation;
    G4VPhysicalVolume* fSecondArmPhys;

    G4bool fUseLocalMagField;
};

#endif

