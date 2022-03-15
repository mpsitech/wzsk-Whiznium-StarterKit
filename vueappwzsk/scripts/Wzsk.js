export default {
	title: "Whiznium StarterKit",

	version: "1.0.12",

	appsrvport: function() {
		if (process.env.NODE_ENV === "development") return "13100"; // IP appsrvport --- LINE
		else return window.location.port
	},

	unescapeString: function(str) {
		var str2 = str;
		var ss = str.split("\\u");

		if (ss.length > 0) {
			str2 = ss[0];

			for (var i = 1; i < ss.length; i++)
				if (ss[i].length >= 4)
					str2 = str2 + String.fromCharCode(256*parseInt(ss[i].substr(0,2), 16) + parseInt(ss[i].substr(2,2), 16)) + ss[i].substr(4);
		}

		return str2;
	},

	unescapeBlock: function(blk) {
		for (let bit in blk)
			if (typeof(blk[bit]) == "string")
				blk[bit] = this.unescapeString(blk[bit]);
	}
}
