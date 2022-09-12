<template>
	<v-container v-if="initdone">
		<PnlWzskPrsList
			v-on:request="handleRequest"
			ref="PnlWzskPrsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskPrsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskPrsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskPrsList from './PnlWzskPrsList';
	import PnlWzskPrsRec from './PnlWzskPrsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskPrs',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskPrsList,
			PnlWzskPrsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskPrs.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskPrs) this.continf = dpcheng.ContInfWzskPrs;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskPrs) this.statapp = dpcheng.StatAppWzskPrs;
				if (dpcheng.StatShrWzskPrs) this.statshr = dpcheng.StatShrWzskPrs;
				if (dpcheng.TagWzskPrs) {
					Wzsk.unescapeBlock(dpcheng.TagWzskPrs);
					this.tag = dpcheng.TagWzskPrs;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskPrsList.handleReply(obj);
					else this.$refs.PnlWzskPrsRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskPrsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskPrsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskPrsRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
