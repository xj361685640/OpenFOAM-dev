/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2024 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "Sine.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
Foam::Function1s::Sine<Type>::Sine
(
    const word& name,
    const dictionary& dict
)
:
    FieldFunction1<Type, Sine<Type>>(name),
    amplitude_(Function1<Type>::New("amplitude", dict)),
    frequency_(dict.lookup<scalar>("frequency")),
    start_(dict.lookupOrDefault<scalar>("start", 0)),
    level_(Function1<Type>::New("level", dict)),
    integrable_(amplitude_->constant() && level_->constant())
{}


template<class Type>
Foam::Function1s::Sine<Type>::Sine(const Sine<Type>& se)
:
    FieldFunction1<Type, Sine<Type>>(se),
    amplitude_(se.amplitude_, false),
    frequency_(se.frequency_),
    start_(se.start_),
    level_(se.level_, false),
    integrable_(se.integrable_)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class Type>
Foam::Function1s::Sine<Type>::~Sine()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
void Foam::Function1s::Sine<Type>::write(Ostream& os) const
{
    writeEntry(os, amplitude_());
    writeEntry(os, "frequency", frequency_);
    writeEntry(os, "start", start_);
    writeEntry(os, level_());
}


// ************************************************************************* //
