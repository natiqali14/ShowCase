#pragma once


UENUM(BlueprintType)
enum class EBlackMagic : uint8
{
	EBM_FireBall UMETA("Fire Ball"),
	EBM_ElectroSpark UMETA("Electro Spark"),
	EBM_BloodLust UMETA("Blood Lust"),
	EBM_ArtciBlast UMETA("Artic Blast"),
	EBM_Default UMETA("Default")
};


UENUM(BlueprintType)
enum class EWhiteMagic : uint8
{
	EWM_LensOfTruth UMETA("Len of Truth"),
	EWM_Mist UMETA("Mist"),
	EWM_Shield UMETA("Shield"),
	EWM_TimeSlow UMETA("TimeSlow"),
	EWM_Default UMETA("Default")
};
