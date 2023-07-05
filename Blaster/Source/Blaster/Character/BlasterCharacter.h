// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BlasterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;


UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

protected:
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* BlasterContext;

		///** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MovementAction;

  ///** Look Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
  UInputAction* LookAction;

private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* OverheadWidget;


public:


};
