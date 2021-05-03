import { $ } from './common.js'

function readFile (event) {
	const file = event.target.files[0];
	const reader = new FileReader()

	reader.onload = (e) => {
		console.log(e.target.result.length)
	}
	reader.readAsBinaryString(file)
}

export default { readFile }
