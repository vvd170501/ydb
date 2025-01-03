#include "backup_restore_common.h"

namespace NKikimr::NDataShard::NBackupRestore {

void TMetadata::AddFullBackup(TFullBackupMetadata::TPtr fb) {
    FullBackups.emplace(fb->SnapshotVts, fb);
}

void TMetadata::SetVersion(ui64 version) {
    Version = version;
}

TString TMetadata::Serialize() const {
    NJson::TJsonMap m;
    m["version"] = Version;
    NJson::TJsonArray fullBackups;
    for (auto &[tp, _] : FullBackups) {
        NJson::TJsonMap backupMap;
        NJson::TJsonArray vts;
        vts.AppendValue(tp.Step);
        vts.AppendValue(tp.TxId);
        backupMap["snapshot_vts"] = std::move(vts);
        fullBackups.AppendValue(std::move(backupMap));
    }
    m["full_backups"] = fullBackups;
    return NJson::WriteJson(&m, false);
}

} // NKikimr::NDataShard::NBackupRestore
