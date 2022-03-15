<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">System configuration</h1>
		<PnlWzskScfConn
			v-on:request="handleRequest"
			ref="PnlWzskScfConn"
			:scrJref=statshr.scrJrefConn
		/>
		<PnlWzskScfGeom
			v-on:request="handleRequest"
			ref="PnlWzskScfGeom"
			:scrJref=statshr.scrJrefGeom
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskScfConn from './PnlWzskScfConn';
	import PnlWzskScfGeom from './PnlWzskScfGeom';
	/*
	*/

	export default {
		name: 'CrdWzskScf',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskScfConn,
			PnlWzskScfGeom
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskScf.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskScf) this.continf = dpcheng.ContInfWzskScf;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskScf) this.statapp = dpcheng.StatAppWzskScf;
				if (dpcheng.StatShrWzskScf) this.statshr = dpcheng.StatShrWzskScf;
				if (dpcheng.TagWzskScf) {
					Wzsk.unescapeBlock(dpcheng.TagWzskScf);
					this.tag = dpcheng.TagWzskScf;
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
					if (obj.dpcheng.scrJref == this.statshr.scrJrefConn) this.$refs.PnlWzskScfConn.handleReply(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefGeom) this.$refs.PnlWzskScfGeom.handleReply(obj);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskScfData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefConn) this.$refs.PnlWzskScfConn.handleUpdate(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefGeom) this.$refs.PnlWzskScfGeom.handleUpdate(obj);
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
