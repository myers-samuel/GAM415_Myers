// Copyright Epic Games, Inc. All Rights Reserved.

#include "myersfirstperson415PickUpComponent.h"

Umyersfirstperson415PickUpComponent::Umyersfirstperson415PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void Umyersfirstperson415PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &Umyersfirstperson415PickUpComponent::OnSphereBeginOverlap);
}

void Umyersfirstperson415PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	Amyersfirstperson415Character* Character = Cast<Amyersfirstperson415Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
