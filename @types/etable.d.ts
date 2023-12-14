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
 * Functions for interacting with the etable native extension.
 * @noResolution
 * @namespace
 */
declare namespace etable {
	/**
	 * Clears all values from the given table.
	 * @param {Table<any>} table - The table to be emptied.
	 */
	export function empty(table: Table<any>): void;

	/**
	 * Finds the index/key of the first occurrence of a value in a table.
	 * @param {Table<any>} table - The table to search.
	 * @param {any} value - The value to search for.
	 * @returns {number | undefined} The index of the first occurrence of the value, or undefined if not found.
	 */
	export function index_of(
		table: Table<any>,
		value: any,
	): number | string | undefined;

	/**
	 * Removes a value with a specific key from a table.
	 * @param {Table<any>} table - The table from which to remove the element.
	 * @param {any} key - The key of the element to remove.
	 */
	export function remove(table: Table<any>, key: any): void;

	/**
	 * Creates a new table containing a subset of the elements from an existing table.
	 * @param {Table<T>} table - The table to slice.
	 * @param {number} [start=1] - The starting index.
	 * @param {number} [end] - The ending index (exclusive).
	 * @returns {Table<T>} A new array containing the sliced elements.
	 * @template T - The type of elements in the table.
	 */
	export function slice<T>(
		table: Table<T>,
		start?: number,
		end?: number,
	): Table<T>;
}
