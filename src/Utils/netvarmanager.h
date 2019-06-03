#pragma once

#include <string>
#include <vector>

#include "../SDK/IBaseClientDLL.h" //RecvTable/RecvProp

namespace NetVarManager {
    std::vector<RecvTable *> GetTables();

    RecvTable *GetTable(std::vector<RecvTable *> tables, const char *tableName);

    int GetOffset(std::vector<RecvTable *> tables, const char *tableName, const char *propName);

    int GetProp(std::vector<RecvTable *> tables, const char *tableName, const char *propName, RecvProp **prop = 0);

    int GetProp(std::vector<RecvTable *> tables, RecvTable *recvTable, const char *propName, RecvProp **prop = 0);

    std::string DumpTable(RecvTable *table, int depth);

    bool HookProp(const char *tableName, const char *propName, RecvVarProxyFn f);

    void DumpNetvars();
}
