#include <dmsdk/sdk.h>

static int eTable_empty(lua_State* L)
{
    // Check if an argument is provided and it is a table
    if (lua_istable(L, 1))
    {
        // Clear the table
        lua_pushnil(L);
        while (lua_next(L, 1) != 0)
        {
            // Remove the key-value pair from the table
            lua_pop(L, 1);
            lua_pushvalue(L, -1);  // Duplicate the value
            lua_pushnil(L);        // Set the value to nil
            lua_rawset(L, 1);      // Update the table
        }
    }
    else
    {
        // If the argument is not a table, handle the error or do nothing
        luaL_error(L, "etable.empty() requires a table as an argument");
    }

    // Do not return anything, just modify the table in place
    return 0;
}

static int eTable_remove(lua_State* L)
{
    // Check if the first argument is a table
    if (lua_istable(L, 1))
    {
        // Get the number of arguments
        int numArgs = lua_gettop(L);

        // Check if the second argument is provided
        if (numArgs >= 2)
        {
            // Iterate through the table to find the value and remove it
            lua_pushnil(L);
            while (lua_next(L, 1) != 0)
            {
                // Duplicate the key and compare the values
                lua_pushvalue(L, -2);
                int isEqual = lua_rawequal(L, -1, 2);

                // Pop the duplicated key
                lua_pop(L, 1);

                if (isEqual)
                {
                    // Remove the key-value pair from the table
                    lua_pop(L, 1);
                    lua_pushnil(L);
                    lua_rawset(L, 1);

                    // Value found and removed, exit the loop
                    break;
                }

                // Move to the next key-value pair
                lua_pop(L, 1);
            }
        }
        else
        {
            luaL_error(L, "etable.remove() requires a value to remove as the second argument");
        }
    }
    else
    {
        luaL_error(L, "etable.remove() requires a table as the first argument");
    }

    // Do not return anything, just modify the table in place
    return 0;
}

static int eTable_indexOf(lua_State* L)
{
    // Check if the first argument is a table
    if (lua_istable(L, 1))
    {
        // Get the number of arguments
        int numArgs = lua_gettop(L);

        // Check if at least two arguments are provided
        if (numArgs >= 2)
        {
            // Iterate through the table to find the key of the value
            lua_pushnil(L);
            while (lua_next(L, 1) != 0)
            {
                if (lua_rawequal(L, -1, 2)) {
                    lua_pushvalue(L, -2);
                    return 1;
                }
                lua_pop(L, 1);
            }
        }
        else
        {
            luaL_error(L, "etable.indexOf() requires at least two arguments");
        }
    }
    else
    {
        luaL_error(L, "etable.indexOf() requires a table as the first argument");
    }

    return 0;
}

static int eTable_slice(lua_State* L)
{
    // Check if the first argument is a table
    if (lua_istable(L, 1))
    {
        // Get the number of arguments
        int numArgs = lua_gettop(L);

        // Get the start and end indices
        int start = (numArgs >= 2) ? luaL_optinteger(L, 2, 1) : 1;
        int end = (numArgs >= 3) ? luaL_optinteger(L, 3, lua_objlen(L, 1)) : lua_objlen(L, 1);

        // Adjust indices to be within valid range
        start = (start < 0) ? lua_objlen(L, 1) + start + 1 : start;
        end = (end < 0) ? lua_objlen(L, 1) + end + 1 : end;

        // Create a new table and copy elements from the original table
        lua_createtable(L, end - start + 1, 0);
        int newLength = 1;

        for (int i = start; i <= end; ++i)
        {
            lua_rawgeti(L, 1, i);

            // If the value is not nil, add it to the new table
            if (!lua_isnil(L, -1))
            {
                lua_rawseti(L, -2, newLength++);
            }
            else
            {
                // Pop the nil value if it exists
                lua_pop(L, 1);
            }
        }

        return 1;  // Return the new sliced table
    }
    else
    {
        luaL_error(L, "etable.slice() requires a table as the first argument");
    }

    // Return nil if there was an error
    lua_pushnil(L);
    return 1;
}

static const luaL_Reg etable_functions[] =
{
    { "empty", eTable_empty },
    { "remove", eTable_remove },
    { "index_of", eTable_indexOf },
    { "slice", eTable_slice },
    { 0, 0 }
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, "etable", etable_functions);
    lua_pop(L, 1);
}

static dmExtension::Result Initialize(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension\n", "etable");
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(etable, "etable", 0, 0, Initialize, 0, 0, 0)
