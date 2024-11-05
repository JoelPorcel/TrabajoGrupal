// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"


UCLASS()
class DONKEYKONG_USFX_API AMuro : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMuro();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class ABarrilExplosivo* Barril;


protected:
	//El nombre del muro
	FString NombreDelMuro;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	class UComponenteExtra* Componenteextra;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* MuroMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* MuroCollision;

	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	bool moverse;
	bool desaparecer;
	float cambio;
	int ContadorCambio;
	FTimerHandle Timer;

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	virtual void Mensaje();

public:
	void destruirBarril();

	virtual void armarMuro();

	FORCEINLINE FString ObtenerNombreDelMuro();

};
