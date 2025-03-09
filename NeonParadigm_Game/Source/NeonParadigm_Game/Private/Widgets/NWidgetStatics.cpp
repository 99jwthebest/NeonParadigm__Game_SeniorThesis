// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NWidgetStatics.h"
#include "Components/PanelWidget.h"

TArray<class UWidget*> UNWidgetStatics::GetAllChildrenInTree(UPanelWidget* Parent)
{
	TArray<UWidget*> AllChildrenInTree;
	TArray<UWidget*> Children = Parent->GetAllChildren();
	for (UWidget* Child : Children)
	{
		AllChildrenInTree.Add(Child);
		UPanelWidget* ChildPanelWidget = Cast<UPanelWidget>(Child);
		if (ChildPanelWidget)
			AllChildrenInTree.Append(GetAllChildrenInTree(ChildPanelWidget));
	}
	return AllChildrenInTree;
}
