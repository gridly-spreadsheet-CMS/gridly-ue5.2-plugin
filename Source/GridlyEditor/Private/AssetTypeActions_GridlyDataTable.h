#pragma once

#include "AssetTypeActions_CSVAssetBase.h"
#include "AssetDefinitionDefault.h"
#include "GridlyDataTable.h"
#include "Interfaces/IHttpRequest.h"



class FAssetTypeActions_GridlyDataTable : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GridlyDataTable", "Gridly Data Table"); }
	virtual uint32 GetCategories() { return EAssetTypeCategories::Misc; }
	virtual UClass* GetSupportedClass() const { return UGridlyDataTable::StaticClass(); }
	virtual FColor GetTypeColor() const { return FColor::Blue; }
	virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section);
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>());



private:
	void ExecuteImportFromGridly(TArray<TWeakObjectPtr<UObject>> Objects);
	void ExecuteExportAsCSV(TArray<TWeakObjectPtr<UObject>> Objects);
	void ExecuteExportAsJSON(TArray<TWeakObjectPtr<UObject>> Objects);

private:
	void ImportFromGridly(UGridlyDataTable* DataTable);
	void ExportToGridly(UGridlyDataTable* DataTable);
	void AddToolbarButton(FToolBarBuilder& Builder);

	TQueue<TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>> ExportRequestQueue;
	static TMap<uint32, TSharedPtr<FScopedSlowTask, ESPMode::ThreadSafe>> ImportSlowTasks;
};
