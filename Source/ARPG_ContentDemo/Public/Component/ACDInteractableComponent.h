// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACDInteractableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_CONTENTDEMO_API UACDInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UACDInteractableComponent();

public:
	UFUNCTION(BlueprintCallable, Category="Interactable")
	const bool CanInteract(AActor* Instigator) const { return !bConsumed; }

	UFUNCTION(BlueprintCallable, Category="Interactable")
	void DoInteract(AActor* Instigator);

public:
	// HUD�� ǥ���� ������Ʈ �ؽ�Ʈ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interactable")
	FText PromptText = FText::FromString(TEXT("Interact"));

	// 1ȸ�� ��ȣ�ۿ� ����(����/��ȸ�� ���� ��)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="State")
	bool bSingleUse = false;

	// �̹� ���Ǿ�����(��Ÿ�� ����)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bConsumed = false;

	// ���� ���� ó�� ��������Ʈ ���ε� 
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteracted, AActor*, InstigatorActor);	
	UPROPERTY(BlueprintAssignable)
	FOnInteracted OnInteracted;
};
