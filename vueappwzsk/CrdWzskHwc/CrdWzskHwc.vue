<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">HDR wavelet classification</h1>
		<PnlWzskHwcConfig
			v-on:request="handleRequest"
			ref="PnlWzskHwcConfig"
			:scrJref=statshr.scrJrefConfig
		/>
		<PnlWzskHwcAsys
			v-on:request="handleRequest"
			ref="PnlWzskHwcAsys"
			:scrJref=statshr.scrJrefAsys
		/>
		<PnlWzskHwcDebug
			v-on:request="handleRequest"
			ref="PnlWzskHwcDebug"
			:scrJref=statshr.scrJrefDebug
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskHwcConfig from './PnlWzskHwcConfig';
	import PnlWzskHwcAsys from './PnlWzskHwcAsys';
	import PnlWzskHwcDebug from './PnlWzskHwcDebug';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskHwc',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskHwcConfig,
			PnlWzskHwcAsys,
			PnlWzskHwcDebug
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskHwc.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzskHwc) this.continf = dpcheng.ContInfWzskHwc;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskHwc) this.statapp = dpcheng.StatAppWzskHwc;
				if (dpcheng.StatShrWzskHwc) this.statshr = dpcheng.StatShrWzskHwc;
				if (dpcheng.TagWzskHwc) {
					Wzsk.unescapeBlock(dpcheng.TagWzskHwc);
					this.tag = dpcheng.TagWzskHwc;
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
					if (obj.scrJref == this.statshr.scrJrefConfig) this.$refs.PnlWzskHwcConfig.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefAsys) this.$refs.PnlWzskHwcAsys.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefDebug) this.$refs.PnlWzskHwcDebug.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskHwcData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefConfig) {
						this.$refs.PnlWzskHwcConfig.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefAsys) {
						this.$refs.PnlWzskHwcAsys.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefDebug) {
						this.$refs.PnlWzskHwcDebug.handleUpdate(obj);
						processed = true;
					}
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
