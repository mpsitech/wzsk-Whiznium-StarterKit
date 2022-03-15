<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Live data</h1>
		<PnlWzskLiv2DView
			v-on:request="handleRequest"
			ref="PnlWzskLiv2DView"
			:scrJref=statshr.scrJref2DView
		/>
		<PnlWzskLiv3DView
			v-on:request="handleRequest"
			ref="PnlWzskLiv3DView"
			:scrJref=statshr.scrJref3DView
		/>
		<PnlWzskLivSysmon
			v-on:request="handleRequest"
			ref="PnlWzskLivSysmon"
			:scrJref=statshr.scrJrefSysmon
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskLiv2DView from './PnlWzskLiv2DView';
	import PnlWzskLiv3DView from './PnlWzskLiv3DView';
	import PnlWzskLivSysmon from './PnlWzskLivSysmon';
	/*
	*/

	export default {
		name: 'CrdWzskLiv',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskLiv2DView,
			PnlWzskLiv3DView,
			PnlWzskLivSysmon
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskLiv.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskLiv) this.continf = dpcheng.ContInfWzskLiv;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskLiv) this.statapp = dpcheng.StatAppWzskLiv;
				if (dpcheng.StatShrWzskLiv) this.statshr = dpcheng.StatShrWzskLiv;
				if (dpcheng.TagWzskLiv) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLiv);
					this.tag = dpcheng.TagWzskLiv;
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
					if (obj.dpcheng.scrJref == this.statshr.scrJref2DView) this.$refs.PnlWzskLiv2DView.handleReply(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJref3DView) this.$refs.PnlWzskLiv3DView.handleReply(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefSysmon) this.$refs.PnlWzskLivSysmon.handleReply(obj);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskLivData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJref2DView) this.$refs.PnlWzskLiv2DView.handleUpdate(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJref3DView) this.$refs.PnlWzskLiv3DView.handleUpdate(obj);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefSysmon) this.$refs.PnlWzskLivSysmon.handleUpdate(obj);
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
