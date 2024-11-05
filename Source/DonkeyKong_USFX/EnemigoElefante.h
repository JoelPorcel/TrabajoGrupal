// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animation/AnimSequence.h" // Include para UAnimSequence
#include "Animation/AnimMontage.h" // Include para UAnimMontage
#include "Enemigos.h"
#include "EnemigoElefante.generated.h"
UCLASS()
class DONKEYKONG_USFX_API AEnemigoElefante : public AEnemigos
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemigoElefante();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Componente de Malla Esquel�tica
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMesh;

	// Asset de animaci�n
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* MyAnimationAsset; // o UAnimMontage* MyAnimationAsset;

public:
	void atacarJugador(APawn* PlayerPawn);
	FTimerHandle Timer;
	void atacar() override;
	void vigilar() override;
	void eliminar() override;
	void spawn(TMap<int, APlataforma*> _Posicion) override;

	APlataforma* Plataforma;
};
