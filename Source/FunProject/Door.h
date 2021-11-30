// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UObject/ConstructorHelpers.h"
#include "Interactable.h"

#include "Door.generated.h"


UCLASS()
class FUNPROJECT_API ADoor : public AActor, public IInteractable 
{
	GENERATED_BODY()

public:	
	ADoor();

	// scene component root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* TheRoot;

	// hinge scene component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* TheHinge;

	// door mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TheMeshDoor;

	// door frame mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UInstancedStaticMeshComponent* TheMeshFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
	float WidthOfDoor = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
	float HeightOfDoor = 300;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
	float DepthOfDoor = 25;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

	virtual void Interact();
};
