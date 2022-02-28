<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Low-level access</h1>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	/*
	*/

	export default {
		name: 'CrdWzskUsr',

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
			//console.log("&Carsref;.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskUsr) this.continf = dpcheng.ContInfWzskUsr;
				if (dpcheng.FeedFSge) this.FeedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskUsr) this.statapp = dpcheng.StatAppWzskUsr;
				if (dpcheng.StatShrWzskUsr) this.statshr = dpcheng.StatShrWzskUsr;
				if (dpcheng.TagWzskUsr) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsr);
					this.tag = dpcheng.TagWzskUsr;
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskUsrData") this.mergeDpchEngData(obj.dpcheng);

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

			FeedFSge: null,

			statapp: null,

			statshr: null,

			tag: null
		})
	}
</script>
