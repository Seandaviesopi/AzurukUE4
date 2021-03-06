

#pragma once

#include "GameFramework/HUD.h"
#include "AzurukHUD.generated.h"

USTRUCT()
struct FCanvasComponent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	FCanvasIcon HUDComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	float xPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	float yPosition;
};


/**
 * 
 */
UCLASS()
class AAzurukHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	/* Main HUD update loop. */
	virtual void DrawHUD() override;

	/* Vital Background Icon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health HUD")
	FCanvasComponent VitalsBack;

	/* Health Bar Icons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health HUD")
	FCanvasComponent HealthBarBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health HUD")
	FCanvasComponent HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health HUD")
	FCanvasComponent HealthIcon;

	/* Morph Bar One Icons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morph One HUD")
	FCanvasComponent MorphBarBack_One;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morph One HUD")
	FCanvasComponent MorphBar_One;

	/* Morph Bar Two Icons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morph Two HUD")
	FCanvasComponent MorphBarBack_Two;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morph Two HUD")
	FCanvasComponent MorphBar_Two;

protected:

	/* Floor for automatic hud scaling. */
	static const float MinHudScale;

	/* UI scaling factor for other resolutions than Full HD. */
	float ScaleUI;

	/* Draw player's health bar. */
	void DrawHealth();

	/* Draw player's morph bars */
	void DrawMorphBarOne();
	void DrawMorphBarTwo();

	void MakeUV(FCanvasIcon&, FVector2D&, FVector2D&, uint16, uint16, uint16, uint16);
	
};
