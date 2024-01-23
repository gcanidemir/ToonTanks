#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	

	public:
		ATank();

		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		virtual void Tick(float DeltaTime) override;
		void HandleDestruction();
		APlayerController* GetTankPlayerController() const {return TankPlayerController;}

		bool bAlive = true;

	protected:
		virtual void BeginPlay() override;

	private:
		UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* SpringArm;

		UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;

		UPROPERTY(EditAnywhere, Category = "Movement")
		float Speed = 700;

		UPROPERTY(EditAnywhere, Category = "Movement")
		float TurnRate = 120;

		UPROPERTY(VisibleAnywhere, Category = "Components")
		APlayerController* TankPlayerController;

		void Move(float Value);
		void Turn(float Value);
};
