<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Files</h1>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	/*
	*/

	export default {
		name: 'CrdWzskFil',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskFil.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskFil) this.continf = dpcheng.ContInfWzskFil;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskFil) this.statapp = dpcheng.StatAppWzskFil;
				if (dpcheng.StatShrWzskFil) this.statshr = dpcheng.StatShrWzskFil;
				if (dpcheng.TagWzskFil) {
					Wzsk.unescapeBlock(dpcheng.TagWzskFil);
					this.tag = dpcheng.TagWzskFil;
				}
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskFilData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					/*
					*/
				}
			},
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null
		})
	}
</script>
