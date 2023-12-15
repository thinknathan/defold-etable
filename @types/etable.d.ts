/** @noSelfInFile */

/**
 * Represents an array in Lua.
 * @template T The type of elements in the table.
 */
type Table<T> =
	| Array<T>
	| { [key: string | number | symbol]: T }
	| Set<T>
	| Map<any, T>;

/**
 * A native extension for Defold with functions to manipulate tables in Lua scripts.
 * @noResolution
 */
declare namespace etable {
	/**
	 * Clears all values from the given table.
	 * @param table - The table to be emptied.
	 */
	export function empty(table: Table<any>): void;

	/**
	 * Removes a value with a specific key from a table.
	 * @param table - The table from which to remove the element.
	 * @param key - The key of the element to remove.
	 */
	export function remove(table: Table<any>, key: any): void;

	/**
	 * Finds the index/key of the first occurrence of a value in the given table.
	 * If the table is structured like an array, the numerical index is returned.
	 * If the table is structured in key/value pairs, the key is returned.
	 * @param table - The table to search.
	 * @param value - The value to search for.
	 * @returns The index of the first occurrence of the value, or undefined if not found.
	 */
	export function index_of(
		table: Table<any>,
		value: any,
	): number | string | undefined;

	/**
	 * Creates a new table containing a subset of the elements from an existing table.
	 * @param table - The table to slice.
	 * @param start - The starting index.
	 * @param end - The ending index (exclusive).
	 * @returns A new array containing the sliced elements.
	 */
	export function slice<T>(
		table: Table<T>,
		start?: number,
		end?: number,
	): Table<T>;
}
