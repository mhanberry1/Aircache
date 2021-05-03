export function $ (queryString) {
	if (queryString[0] == '#')
		return document.querySelector(queryString)	
	else
		return document.querySelectorAll(queryString)
}
