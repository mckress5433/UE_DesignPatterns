// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "DesignPatterns/UI/PlayerHud.h"
#include "GameFramework/Character.h"
#include "InteractionSystemComponent/InteractionComponent.h"

#include "BaseCharacter.generated.h"

class UInputAction;
struct FInputActionValue;

UCLASS()
class DESIGNPATTERNS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly)
	UInteractionComponent* InteractionComp;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPlayerHud> PlayerHudClass;

	UPROPERTY()
	UPlayerHud* PlayerHud; 

protected:
	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* LookAction;

	/** Interaction Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* InteractAction;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UCameraComponent* GetCameraComponent() const { return CameraComp; }
	UPlayerHud* GetPlayerHud() const { return PlayerHud; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);

	/** Called from Input Actions for interacting */
	void InteractInput(const FInputActionValue& Value);
	
	void DoAim(float Yaw, float Pitch);
	void DoMove(float Right, float Forward);
	void DoInteract() const;

	/** Set up input action bindings */
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
